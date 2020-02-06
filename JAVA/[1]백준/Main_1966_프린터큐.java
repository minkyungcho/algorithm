package boj;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main_1966_프린터큐 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		System.setIn(new FileInputStream("res/boj/1966_프린터.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		int result = 0;
		ArrayDeque<Integer> q = new ArrayDeque<>();
		ArrayDeque<Integer> idxq = new ArrayDeque<>();
		for(int test_case=1; test_case<T+1; test_case++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int N = Integer.parseInt(st.nextToken());
			int idx = Integer.parseInt(st.nextToken());
			int max = 0;
			
			StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");
			for(int i=0; i<N; i++) {
				q.offer(Integer.parseInt(st2.nextToken()));
				idxq.offer(i);
			}
			int cnt = 0;
			while(!q.isEmpty()) {
				System.out.println(cnt);
				System.out.println(max);
				for(int i : q) {
					if(max < i) {
						max = i;
					}
				}
				
				if(idxq.peek() == idx) {
					System.out.println("찾았어");
					result = cnt;
					break;
				}
			
				if(q.peek() == max) {
					q.poll();
					idxq.poll();
					cnt++;
//					continue;
				}else {
					q.offer(q.poll());
					idxq.offer(q.poll());
				}
				
			}
			
			
			System.out.println("#"+test_case+" "+result+" "+N+" "+idx+" "+max);
			q.clear();
			idxq.clear();
		}
	}

}
