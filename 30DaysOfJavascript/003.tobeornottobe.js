/**
 * @param {any} val
 * @return {{toBe: (other: any) => boolean, notToBe: (other: any) => boolean}}
 */
var expect = function(val) {
  return {
    toBe: function(other) {
      // Strict equality check
      if (val === other) return true;
      throw new Error("Not Equal");
    },

    notToBe: function(other) {
      // Strict inequality check
      if (val !== other) return true;
      throw new Error("Equal");
    }
  };
};
