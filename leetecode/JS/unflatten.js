/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
var flat = function (arr, n) {
    if(!(arr instanceof Array) ) return [arr]
    if(n==0) return arr;
    let res = []
    arr.forEach(cur => {
        const f = flat(cur,n-1);
        for (const it of f) {
            res.push(it)
        }
    });
    return [...res]
};
console.log(flat( [1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]],2))