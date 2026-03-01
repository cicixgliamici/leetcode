/**
 * LeetCode signature:
 * We must return a function (a "closure") that always returns "Hello World".
 *
 * @return {Function}  // The outer function returns another function (HOF)
 */
var createHelloWorld = function() {

  // Here we return a NEW function object.
  // This returned function can be stored in a variable and called later.
  return function(...args) {

    // Syntax note:
    // "...args" is the REST PARAMETER syntax.
    // It collects all arguments passed to this function into an array named "args".
    // Example: f(1, "a", true) => args becomes [1, "a", true]
    //
    // In this problem we DON'T need the arguments, but we accept them anyway
    // because LeetCode tests may call the function with any number of params.

    // The key requirement:
    // no matter what arguments we receive, we always return the same string.
    return "Hello World";
  };
};
