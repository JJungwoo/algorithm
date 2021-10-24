/*
[LeetCode] 451. Sort Characters By Frequency
https://leetcode.com/problems/sort-characters-by-frequency/
*/

class Solution {
    public String frequencySort(String s) {
        // <알파벳 값, 인덱스>
        HashMap<Character, Integer> map = new HashMap<>();
        // <알파벳 값, 빈도수>
        ArrayList<Obj> list = new ArrayList<>();
        int gidx = 0;
        for (int i=0;i<s.length();i++) {
            int idx = 0;
            idx = checkAndIndexReturn(s.charAt(i), map);
            if (idx == -1) {
                map.put(s.charAt(i), gidx++);
                list.add(new Obj(s.charAt(i), 1));
            } else {
                list.get(idx).frequency++;   
            }            
        }

        Collections.sort(list);
        
        StringBuilder sb = new StringBuilder();
        for (var v : list) {
            for (int i=0;i<v.frequency;i++) {
                sb.append(v.alphabet);
            }
        }
        
        return sb.toString();
    }
    
    private int checkAndIndexReturn(Character val, HashMap<Character, Integer> map) {
        int idx = -1;
        if (map.containsKey(val)) {
            idx = map.get(val);
        }
        return idx;
    }
}

class Obj implements Comparable<Obj> {
    Character alphabet;
    Integer frequency;
    
    Obj (char c, int val) {
        alphabet = c;
        frequency = val;
    }
    
    @Override
    public int compareTo(Obj o) {
        if (this.frequency < o.frequency) {
            return 1;
        }
        return -1;
    }
}
