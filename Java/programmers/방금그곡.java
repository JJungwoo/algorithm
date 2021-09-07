/*
[programmers] 방금그곡
https://programmers.co.kr/learn/courses/30/lessons/17683
*/

import static org.junit.Assert.assertEquals;

import org.junit.Test;

public class 방금그곡 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	}

	static class Solution {
	    public String solution(String m, String[] musicinfos) {
	        String answer = "";
	        int time = 0;
	        m = convertMelody(m);
	        for (String str : musicinfos) {
	            String[] tokens = str.split(",");
	            int diff = timeToint(tokens[1]) - timeToint(tokens[0]);
	            tokens[2] = convertMelody(tokens[2]);
	            tokens[3] = convertMelody(tokens[3]);
	            StringBuffer sb = new StringBuffer();
	            for(int i=0;i<diff;i++) {
	                sb.append(tokens[3].charAt(i % tokens[3].length()));
	            }
	            String temp = convertMelody(sb.toString());
	            if (temp.contains(m) && time < diff) {
	                answer = tokens[2];
	                time = diff;
	            }
	        }
	        if (answer.length() == 0) {
	            answer = "(None)";
	        }
	        return answer;
	    }
	    public int timeToint(String time) {
	        String[] tokens = time.split(":");
	        return Integer.parseInt(tokens[0]) * 60 + Integer.parseInt(tokens[1]);
	    }
	    String convertMelody(String Melody) {
	        Melody = Melody.replaceAll("C#", "H");
	        Melody = Melody.replaceAll("D#", "I");
	        Melody = Melody.replaceAll("F#", "J");
	        Melody = Melody.replaceAll("G#", "K");
	        return Melody.replaceAll("A#", "L");
	    }
	}
	
	@Test
	public void Test() {
		Solution solution = new Solution();
		String[] musicinfos1 = { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" };
		assertEquals("HELLO", solution.solution("ABCDEFG", musicinfos1));
		String[] musicinfos2 = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};
		assertEquals("FOO", solution.solution("CC#BCC#BCC#BCC#B", musicinfos2));
		String[] musicinfos3 = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};
		assertEquals("WORLD", solution.solution("ABC", musicinfos3));
	}
}

