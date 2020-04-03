/*
[programmers] 2020 īī�� ��ä. ���� �˻�
�ܼ� ���� ��ȸ�δ� ���� ���̽� ��� �Ұ��� trie �ڷᱸ�� ����ؾ� �Ѵ�..
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	int qsize = queries.size();
	for (int i = 0; i < qsize; i++) {
		string tmp = queries[i];
		int wsize = words.size();
		int cnt = 0;
		//cout<<tmp<<"\n";
		for (int j = 0; j < wsize; j++) {
			int size = words[j].size();
			int ccnt = 0;
			if (size != tmp.size()) continue;
			for (int c = 0; c < size; c++) {
				if (words[j][c] == tmp[c] || tmp[c] == '?') {
					//cout<<words[j][c]<<","<<tmp[c]<<"\n";
					ccnt++;
				}
			}
			if (ccnt == size) {
				//cout<<"target!!:"<<words[j]<<"\n";
				cnt++;
			}
		}
		answer.push_back(cnt);
	}
	return answer;
}