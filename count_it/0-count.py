#!/usr/bin/python3
"""Count keyword occurrences in a subreddit’s hot article titles."""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """Recursively fetch hot posts and print keyword counts when finished.

    Args:
        subreddit (str): Reddit subreddit name to query.
        word_list (list): Keywords whose title occurrences should be counted.
        after (str, optional): Reddit pagination cursor for internal recursion.
        counts (dict, optional): Accumulated counts for internal recursion.

    Returns:
        None: Prints matching keywords in sorted order, or nothing on failure.
    """
    if counts is None:
        counts = {}
        for keyword in word_list:
            normalized = keyword.lower()
            counts[normalized] = 0

    url = "https://www.reddit.com/r/{}/hot.json?limit=100".format(subreddit)
    if after:
        url += "&after={}".format(after)

    headers = {"User-Agent": "HolbertonSchoolCountIt/1.0"}
    try:
        response = requests.get(
            url,
            headers=headers,
            allow_redirects=False,
            timeout=10,
        )
        if response.status_code != 200:
            return
        posts = response.json()["data"]
    except (requests.RequestException, ValueError, KeyError, TypeError):
        return

    for post in posts.get("children", []):
        title_words = post.get("data", {}).get("title", "").lower().split()
        for keyword in counts:
            occurrences = title_words.count(keyword)
            duplicate_count = sum(
                1 for item in word_list if item.lower() == keyword
            )
            counts[keyword] += occurrences * duplicate_count

    next_after = posts.get("after")
    if next_after:
        count_words(subreddit, word_list, next_after, counts)
        return

    for keyword, count in sorted(
        counts.items(), key=lambda item: (-item[1], item[0])
    ):
        if count:
            print("{}: {}".format(keyword, count))
