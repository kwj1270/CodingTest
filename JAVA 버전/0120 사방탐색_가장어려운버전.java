package com.off.day1;

import java.util.Scanner;


/* 0. 테스트 케이스 입력받기  
 * 1. 2차원 char 배열 생성
 * 2. 배열에 값 하나씩 받아야함 
 * 3. 입력확인 
 * 4. 8방 탐색을 위한 방할 배열 생성(dx, dy)
 * 
 * 
 * 
 * 
 * */
public class MakeBuilding {
	private static final int [] dx = {-1,1,0,0,-1,-1,1,1}; 
	private static final int [] dy = {0,0,-1,1,-1,1,-1,1};
	private static Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args) {
		int t = scanner.nextInt();
		
		for(int test=1; test <= t; test++) {
			int n = scanner.nextInt();
			char[][] map = new char[n][n];
			
			for(int i=0; i < map.length; i++) {
				for(int j=0; j < map[i].length; j++) {
					map[i][j] = scanner.next().charAt(0);
				}	
			}
			
			//print(map);
			
			int maxValue = 0;
			for(int i=0; i < map.length; i++) {
				for(int j=0; j < map[i].length; j++) {
					if(map[i][j] == 'G') continue;
					int sum = 0;		
					boolean flag = true;
					for(int k=0; k < 8; k++) {
						int nx = i+dx[k];
						int ny = j+dy[k];
						if(nx < 0 || nx >= map.length) continue;
						if(ny < 0 || ny >= map[i].length) continue;
						if(map[nx][ny] == 'G') {sum = 2; flag = false; break;}
					}
					if(flag) sum = getSum(map, i, j);
					maxValue = Math.max(maxValue, sum);
				}	
			}
			System.out.println("#"+test + " " + maxValue);
		}
	}
	
	public static int getSum(char[][] map, int x, int y) {
		int sum = 0;
		for(int i=0; i < map.length; i++) {
			if(map[i][y] == 'B') {
				sum +=1;
			}
		}
		for(int i=0; i < map[x].length; i++) {
			if(map[x][i] == 'B') {
				sum += 1;
			}
		}
		sum -= 1;
		return sum;
	}
	
	public static void print(char[][] map) {
		for(int i=0; i < map.length; i++) {
			for(int j=0; j < map[i].length; j++) {
				System.out.print(map[i][j]+"\t");
			}	
			System.out.println();
		}
		System.out.println("\n");
	}

}
