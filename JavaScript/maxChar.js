// --- Directions
// Given a string, return the character that is most
// commonly used in the string.
// --- Examples
// maxChar("abcccd") === "c"
// maxChar("hacktoberfest 11111") === "1"

function maxChar(str) {
  const chars = {};
  let max = 0;
  let maxChar = "";

  for (const char of str) {
    if (!chars[char]) {
      chars[char] = 1;
    } else {
      chars[char]++;
    }
  }

  for (const key in chars) {
    if (chars[key] > max) {
      max = chars[key];
      maxChar = key;
    }
  }

  return maxChar;
}

module.exports = maxChar;
