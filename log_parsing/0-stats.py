#!/usr/bin/python3
import sys

total_size = 0
status_codes = {}
line_count = 0

def print_stats():
    print("File size: {}".format(total_size))
    for code in sorted(status_codes):
        print("{}: {}".format(code, status_codes[code]))

try:
    for line in sys.stdin:
        parts = line.split()
        total_size += int(parts[-1])
        line_count += 1
        status = parts[-2]
        valid = [200, 301, 400, 401, 403, 404, 405, 500]

        if status.isdigit() and int(status) in valid:
            code = int(status)
            if code in status_codes:
                status_codes[code] += 1
            else:
                status_codes[code] = 1

        if line_count % 10 == 0: 
            print_stats()
except KeyboardInterrupt:
    print_stats()

