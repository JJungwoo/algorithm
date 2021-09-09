/*
[programmers] 위클리 챌린지 4주차 직업군 추천하기
https://programmers.co.kr/learn/courses/30/lessons/84325
*/
import static org.junit.Assert.assertEquals;
import java.util.*;
import org.junit.Test;

public class 직업군추천하기 {
	public static void main(String[] args) {
		
	}
	
	@Test
	public void test() {
		Solution so = new Solution();
		String[] table1 = {"SI JAVA JAVASCRIPT SQL PYTHON C#", 
				"CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", 
				"HARDWARE C C++ PYTHON JAVA JAVASCRIPT", 
				"PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", 
				"GAME C++ C# JAVASCRIPT C JAVA"};
		String[] languages1 = {"PYTHON", "C++", "SQL"};
		int[] perference1 = {7, 5, 5};
		assertEquals("HARDWARE", so.solution(table1, languages1, perference1));
		String[] table2 = {"SI JAVA JAVASCRIPT SQL PYTHON C#", 
				"CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", 
				"HARDWARE C C++ PYTHON JAVA JAVASCRIPT", 
				"PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", 
				"GAME C++ C# JAVASCRIPT C JAVA"};
		String[] languages2 = {"JAVA", "JAVASCRIPT"};
		int[] perference2 = {7, 5};
		assertEquals("PORTAL", so.solution(table2, languages2, perference2));
	}
	
	class Solution {
	    public String solution(String[] table, String[] languages, int[] preference) {
	        String answer = "";
	        HashMap<String, Integer> mapPf = new HashMap<>();
	        ArrayList<JobResult> alist = new ArrayList<>();
	        for(int i=0;i<languages.length;i++) {
	        	mapPf.put(languages[i], preference[i]);
	        }
	        
	        int maxValue = 0;
	        for(int i=0;i<table.length;i++) {
	            String[] tokens = table[i].split(" ");
	            int sum = 0;
	            for(int j=1;j<tokens.length;j++) {
	            	if (mapPf.containsKey(tokens[j])) {
	            		sum += mapPf.get(tokens[j]) * (tokens.length - j);
	            	}
	            }
	            if (sum >= maxValue) {
	            	maxValue = sum;
	            	answer = tokens[0];
	            	alist.add(new JobResult(tokens[0], sum));
	            }
	        }
	        alist.sort(new Comparator<JobResult>() {

				@Override
				public int compare(JobResult o1, JobResult o2) {
					int ret = o2.totalScore - o1.totalScore;
					if (ret == 0) {
						ret = o1.jobName.compareTo(o2.jobName);
					}
					return ret;
				}

	        });
	        return answer = alist.get(0).jobName;
	    }
	}
	class JobResult {
		String jobName;
		int totalScore;
		public JobResult(String jobName, int totalScore) {
			this.jobName = jobName;
			this.totalScore = totalScore;
		}
	}
}
