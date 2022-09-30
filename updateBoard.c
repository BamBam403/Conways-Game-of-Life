/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */



int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
  int count = 0;
  for (int i = row-1; i <= row+1; i++){
    if (i >= 0 && i < boardRowSize)
      for (int z = col-1; z <= col+1; z++){
	if (z >= 0 && z < boardColSize)
	  if (i != row || z != col)
	    if (board[(boardColSize*i)+z])
	      count++;
      }
  }
  return count;
}

/*
 * Update the game board to the next step.
 * Input: 
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) {
  
  int x,y;
  
  int size = boardRowSize*boardColSize;
  int clone[size];


  for (x = 0; x < boardRowSize; x++){
    for (y = 0; y < boardColSize; y++){  
      if (board[x*boardColSize+y] == 1){
	if (countLiveNeighbor(board, boardRowSize, boardColSize, x, y) > 3 || countLiveNeighbor(board, boardRowSize, boardColSize, x, y) < 2){
	clone[(x*boardColSize)+y] = 0;
	}
	else {
	  clone[(x*boardColSize)+y] = 1;
	}
      }
      else {
	if (countLiveNeighbor(board, boardRowSize, boardColSize, x, y) == 3){
    clone[(x*boardColSize)+y] = 1;
	}
	else {
	  clone[(x*boardColSize)+y] = 0;
	}
      }
    }
  }
  for (int f = 0; f < size; f++){
    board[f] = clone[f];
  }
}
/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with 
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */ 
int aliveStable(int* board, int boardRowSize, int boardColSize){

    int size = boardRowSize*boardColSize;
    int clone[size];
   for (int f = 0; f < size; f++){
     clone[f] = board[f];
    }
 for (int x = 0; x < boardRowSize; x++){
    for (int y = 0; y < boardColSize; y++){  
      if (board[x*boardColSize+y] == 1){
	if (countLiveNeighbor(board, boardRowSize, boardColSize, x, y) > 3 || countLiveNeighbor(board, boardRowSize, boardColSize, x, y) < 2){
	clone[(x*boardColSize)+y] = 0;
	}
	else {
	  clone[(x*boardColSize)+y] = 1;
	}
      }
      else {
	if (countLiveNeighbor(board, boardRowSize, boardColSize, x, y) == 3){
    clone[(x*boardColSize)+y] = 1;
	}
	else {
	  clone[(x*boardColSize)+y] = 0;
	}
      }
    }
  } 
  for (int b = 0; b < size; b++){
        if (board[b] != clone[b]){
      return 0;
     }
   }
    return 1;
}

				
				
			

