/*
[programmers] 신고 결과 받기
https://programmers.co.kr/learn/courses/30/lessons/92334
*/
import java.util.*;
class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        Map<String, User> userMap = new HashMap<>();

        for (String str : id_list) {
            userMap.put(str, new User(str, 0));
        }

        for (String str : report) {
            String[] tokens = str.split(" ");
            User u = userMap.get(tokens[0]);
            if (u.reportUsers.contains(tokens[1])) {
                continue;
            }
            u.reportUsers.add(tokens[1]);
            userMap.get(tokens[1]).reportedCnt++;
        }

        for (int i = 0; i < id_list.length; i++) {
            List<String> tmpList = userMap.get(id_list[i]).reportUsers;
            int reportedSuccessCnt = 0;
            for (String reportUser : tmpList) {
                if (userMap.get(reportUser).reportedCnt >= k) {
                    reportedSuccessCnt++;
                }
            }
            answer[i] = reportedSuccessCnt;
        }
        return answer;
    }
}

class User {
    String name;
    int reportedCnt;
    List<String> reportUsers = new ArrayList<>();

    public User(String name, int reportedCnt) {
        this.name = name;
        this.reportedCnt = reportedCnt;
    }
}
