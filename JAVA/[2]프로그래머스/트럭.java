package code;

import java.util.LinkedList;
import java.util.Queue;

public class Truck {

	public static void main(String[] args) {
		int bridge_length = 100; // 2
		int weight = 100; // 10
		int[] truck_weights = {10,10,10,10,10,10,10,10,10,10}; // {7,4,5,6}
		int time = 0;
        int sum = 0;
        int answer = 0;
        Queue<Integer> q = new LinkedList<Integer>();
        // �ٸ� ���̸�ŭ ť�� 0 �ֱ�
        for(int i=0; i<bridge_length; i++){
            q.add(0);
        }
        for(int i=0; i<truck_weights.length; i++) {
        	// 1�� ���� �ٸ� ���� �տ� �ִ� Ʈ�� ���� 
        	sum -= q.poll();
        	// �ʰ����� ������ Ʈ�� ť�� �ֱ�
        	if(sum + truck_weights[i] <= weight) {
        		// ���� Ʈ�� ť�� ����
        		q.add(truck_weights[i]);
        		// sum�� ���� Ʈ�� ���� ���ϱ�
        		sum += truck_weights[i];
        	}else { // �ʰ��Ѵٸ� 0�� ť�� �ֱ� 
        		// 0 �ֱ�
        		q.add(0);
        		// ���� Ʈ���� ť�� �������� for�� �ٽ� ������ ���� �ε��� ����
        		i--;
        	}
        	// for�� ���ư������� 1�ʾ� ����
        	time++;
        }
        // ������ Ʈ������ �ְ� ���Ŀ��� ������ Ʈ���� �ٸ� �������ö������� ���ؾ���.
        answer = time + bridge_length;
        System.out.println(answer);
	}
}
