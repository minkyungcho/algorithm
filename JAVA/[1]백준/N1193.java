package day04;

import java.util.Scanner;

public class c1Q1193 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int input = sc.nextInt();

		int cnt = 0;

		int line = 0; // ���° ��

		int num = 0; //

		int order = 0; // ���° ����

		int denominator = 0; // ����

		int numerator = 0; // �и�

		// ���° ������ ���

		for (int i = 1; i <= input; i++) {

			if (cnt >= input) {

				break;

			}

			line++;

			cnt += i;

		}

		// ���° �������� ���

		num = (line - 1) * line / 2; // ��������

		order = input - num;

		// Ȧ����° ��

		// ���� : 1 - 3 2 1 - 5 4 3 2 1 - 7 6 5 4 3 2 1 - ...

		// �и� : 1 - 1 2 3 - 1 2 3 4 5 - 1 2 3 4 5 6 7 - ...

		if (line % 2 == 1) {

			// ����

			denominator = line - (order - 1);

			// �и�

			numerator = order;

			// ���

			System.out.println(denominator + "/" + numerator);

		}

		// ¦����° ��

		// ���� : 1 2 - 1 2 3 4 - 1 2 3 4 5 6 - ...

		// �и� : 2 1 - 4 3 2 1 - 6 5 4 3 2 1 - ...

		else {

			// ����

			denominator = order;

			// �и�

			numerator = line - (order - 1);

			// ���

			System.out.println(denominator + "/" + numerator);

		}
	}

}
