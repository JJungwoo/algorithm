/*
[LeetCode] 797. All Paths From Source to Target
https://leetcode.com/problems/all-paths-from-source-to-target/
*/

class Solution {
    private List<List<Integer>> answer;
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        answer = new ArrayList<>();
        List<Integer> tempList = new ArrayList<>();
        
        tempList.add(0);
        dfs(0, graph, tempList);
        
        return answer;
    }
    
    private void dfs(int idx, int[][] graph, List<Integer> visitedList) {
        
        if (idx == graph.length - 1) {
            answer.add(new ArrayList<Integer>(visitedList));
            return;
        }
        
        for (int i = 0; i < graph[idx].length; i++) {
            visitedList.add(graph[idx][i]);
            dfs(graph[idx][i], graph, visitedList);
            visitedList.remove(visitedList.size() - 1); 
        }
    }
}
