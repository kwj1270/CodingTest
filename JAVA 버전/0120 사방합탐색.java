package com.off.day1;

// 4방 탐색해서 그 값을 더하는 것 
public class ArrayDirectionSum {
	
	public static void main(String[] args) {
		int[][] data = {
				{1,2,3,4,5},
				{1,2,3,4,5},
				{1,2,3,4,5},
				{1,2,3,4,5},
				{1,2,3,4,5}				
		}; // 사용할 배열 
	
		for(int i=0; i < data.length; i++) {
			for(int j=0; j < data[i].length; j++) {
				System.out.print(data[i][j]+"\t");
			}	
			System.out.println();
		}
		System.out.println("\n");

		// 상하좌우 방향 접근할 때 사용할 인덱스 {상, 하, 좌, 우}     
		int [] dx = {-1,1,0,0}; 
		int [] dy = {0,0,-1,1};
		
		// int[][]dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		
		for(int i=0; i < data.length; i++) {
			for(int j=0; j < data[i].length; j++) {
				int sum = data[i][j];			// 시작값
				for(int k=0; k < 4; k++) {
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(nx < 0 || nx >= data.length) continue;
					if(ny < 0 || ny >= data[i].length) continue;
					sum += data[nx][ny]; 		// 누적값
				} // k
				System.out.print(sum + "\t");
			} 
			System.out.println();
		}
		
	}
	
	
}
