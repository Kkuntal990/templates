ll parents[NMAX];
ll size[NMAX];

int Find(int x) {
	int tx, rx;
	tx = x;
	while (parent[tx] > 0)
		tx = parent[tx];
  // for path compression
	while (x != tx) {
		rx = parent[x];
		parent[x] = tx;
		x = rx;
	}
	
	return tx;
}

void Union(int i, int j) {
	int ti = Find(i), tj = Find(j);
	if (ti == tj)
		return;
	if (size[ti] >= size[tj]) {
		parent[tj] = ti;
		size[ti] += size[tj];
	} else {
		parent[ti] = tj;
		size[tj] += size[ti];
	}
}
