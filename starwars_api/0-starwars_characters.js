#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];
const movieUrl = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(movieUrl, (error, response, body) => {
  if (error || response.statusCode !== 200) {
    return;
  }

  const characters = JSON.parse(body).characters;
  let index = 0;

  const printNextCharacter = () => {
    if (index === characters.length) {
      return;
    }

    request(characters[index], (characterError, characterResponse, characterBody) => {
      if (!characterError && characterResponse.statusCode === 200) {
        console.log(JSON.parse(characterBody).name);
      }
      index += 1;
      printNextCharacter();
    });
  };

  printNextCharacter();
});
