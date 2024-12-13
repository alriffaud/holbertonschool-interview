#!/usr/bin/node

// Import the 'request' module to perform HTTP requests
const request = require('request');

// Retrieve the movie ID from the command-line arguments
const movieId = process.argv[2];

// Construct the URL for the Star Wars API endpoint for the given movie ID
const url = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;

// Make a GET request to the API to fetch movie details
request(url, (error, response, body) => {
  // Check if there was an error in the request
  if (error) {
    console.error('Error fetching movie data:', error);
    return;
  }

  // Parse the API response body (JSON string) into a JavaScript object
  const data = JSON.parse(body);

  // Retrieve the list of character URLs from the response
  const characters = data.characters;

  // Define a function to fetch and print each character's name in order
  const fetchCharacter = (index) => {
    // Base case: If all characters are processed, stop recursion
    if (index >= characters.length) {
      return;
    }

    // Make a GET request to fetch details of the character at the current index
    request(characters[index], (err, res, charBody) => {
      if (err) {
        console.error('Error fetching character data:', err);
        return;
      }

      // Parse the character's data and print the name
      const characterData = JSON.parse(charBody);
      console.log(characterData.name);

      // Recursive call to process the next character
      fetchCharacter(index + 1);
    });
  };

  // Start fetching characters from the beginning of the list
  fetchCharacter(0);
});
