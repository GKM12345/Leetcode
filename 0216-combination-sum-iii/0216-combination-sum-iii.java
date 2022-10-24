class Solution {
    public void helper(int i, int k, int n, List<List<Integer>> ans, List<Integer> sub){


    if( n == 0 && sub.size() == k){

        ans.add(new ArrayList<>(sub));

        return;

    }


    if(n < 0 || i == 10){

        return;

    }


    helper(i+1, k, n, ans, sub);

    sub.add(i);

    helper(i+1, k, n-i, ans, sub);

    sub.remove(sub.size()-1);

}



public List<List<Integer>> combinationSum3(int k, int n) {


    List<List<Integer>> ans = new ArrayList<>();


    List<Integer> sub = new ArrayList<>();


    helper(1, k, n, ans, sub);


    return ans;


}


}