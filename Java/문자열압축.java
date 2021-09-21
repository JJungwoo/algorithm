/*
[programmers] 2020 KAKAO BLIND RECRUITMENT 문자열 압축
https://programmers.co.kr/learn/courses/30/lessons/60057
*/

class Solution {
    public int solution(String s) {
        int answer = s.length();
        for (int size=1;size<=s.length() / 2;size++) {
            StringBuffer sb = new StringBuffer();
            int idx = 0, cnt = 1;
            sb.append(s.substring(0, idx));

            String tmp = s.substring(idx, idx + size);
            idx += size;

            while (idx + size <= s.length()) {
                if (s.substring(idx, idx + size).equals(tmp)) {
                    idx += size;
                    cnt++;
                } else {
                    if (cnt > 1) {
                        sb.append(String.valueOf(cnt));
                    }
                    sb.append(tmp);
                    tmp = s.substring(idx, idx + size);
                    idx += size;
                    cnt = 1;
                }
            }
            if (cnt > 1) {
                sb.append(String.valueOf(cnt));
            } 
            sb.append(tmp);
            if (idx < s.length()) {
                sb.append(s.substring(idx, s.length()));
            }
            answer = Math.min(answer, sb.toString().length());
        }
        return answer;
    }
}
