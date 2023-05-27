/**
 * @param {object} obj1
 * @param {object} obj2
 * @return {object}
 */
function objDiff(obj1, obj2) {
    if(!isNaN(obj1) || (Array.isArray(obj1) && !Array.isArray(obj2)) || (!Array.isArray(obj1) && Array.isArray(obj2)))  {
        if(obj1!=obj2) return [obj1,obj2];
        else return null;
    }
    const diff = {}
    let keys;
    if(obj1 instanceof Array) {
        keys = Array.from({length:Math.min(obj1.length,obj2.length)},(_,i)=>i);
    } 
    else{
        keys = Object.keys(obj1);
    }
    if(!keys.length) return null;
    keys.forEach(key => {
        if(obj1 instanceof Object && (!(key in obj1) || !(key in obj2) )) return;
        diff[key] = objDiff(obj1[key],obj2[key]);
        if(!diff[key]) delete diff[key]

    });
    return diff;
};

const obj1 = {
"a": 5, 
"v": 6, 
"z": [1, 2, 4, [2, 5, 7]]
}
const obj2 = {
"a": 5, 
"v": 7, 
"z": [1, 2, 3, [1]]
}
console.log(objDiff(obj1,obj2))