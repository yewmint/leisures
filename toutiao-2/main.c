void traverse(map_t map, int row, int col){
  if (map[row][col] == 1){
    map[row][col] = 0;

    for direction of 8-directions {
      traverse(map, direction.row, direction.col);
    }
  }
}
