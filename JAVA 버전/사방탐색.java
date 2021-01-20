package com.off.day1;

// 4방 탐색  
public class ArrayDirection {
	
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
		
		// 상하좌우 방향 접근할 때 사용할 인덱스 {상, 하, 좌, 우}     
		int [] dx = {-1,1,0,0}; 
		int [] dy = {0,0,-1,1};
		
		// int[][]dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		
		for(int i=0; i < data.length; i++) {
			for(int j=0; j < data[i].length; j++) {
				for(int k=0; k < 4; k++) {
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(nx < 0 || nx >= data.length) continue;
					if(ny < 0 || ny >= data[i].length) continue;
					if(i == 0 && j == 0) System.out.print(data[nx][ny]+"\t");
				} // k
			} 
		}
		
	}
	
	
}
