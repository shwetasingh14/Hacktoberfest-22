// Input
// Array: [1,2,3,4], Chunk Size: 2
// Output
// [[1,2], [3,4]]


function chunk(array, size) {
  let chunked = []
  let index = 0

  while (index < array.length) {
    chunked.push(array.slice(index, index + size))
    index += size;
  }

  return chunked
}

module.exports = chunk;
