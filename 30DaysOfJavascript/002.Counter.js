/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
  // This variable is captured by the returned function (closure).
  // It will persist across multiple calls to counter().
  let current = n;

  return function() {
    // Return the current value, then increment it for the next call.
    // (Post-increment: returns old value, then adds 1.)
    return current++;
  };
};
