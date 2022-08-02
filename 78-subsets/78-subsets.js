/**
 * @param {number[]} nums
 * @return {number[][]}
 */
// var subsets = function(nums) {
    
// };

var makeSubsets = function(nums,n,i,temp,output){  
    
    if(n==i){
        return
    }
    
    makeSubsets(nums,n,i+1,temp,output)
    temp = [...temp,nums[i]]
    makeSubsets(nums,n,i+1,temp,output)     
    output.push(temp)
}

 var subsets = function(nums) {
    let n = nums.length
    
    let output = []
    
   
    makeSubsets(nums,n,0,[],output)   
    output.push([])
        
   
    return output
    
    
};