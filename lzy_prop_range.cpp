//============================================================================
// Name        : SPOJ Multiple by 3 (Segment Tree)
// Author      : Tarango Khan
// Copyright   : Team Byteheads
// Description : !!!Hello World!!!
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define Size 100005

struct vert{
    int cnt[3];
    int prop;
};
vert tree[Size*4];

void build_tree(int cur,int Start,int End){
    if(Start == End){
        tree[cur].cnt[0] = 1;
        tree[cur].cnt[1] = 0;
        tree[cur].cnt[2] = 0;
        tree[cur].prop = 0;
        return;
    }
    int left = cur*2;
    int right = left+1;
    int mid = (Start+End)/2;
    build_tree(left,Start,mid);
    build_tree(right,mid+1,End);
    tree[cur].cnt[0] = tree[left].cnt[0] + tree[right].cnt[0];
    tree[cur].cnt[1] = tree[left].cnt[1] + tree[right].cnt[1];
	tree[cur].cnt[2] = tree[left].cnt[2] + tree[right].cnt[2];
	tree[cur].prop = tree[left].prop + tree[right].prop;
}

void update_prop(int cur){
	int tmp = tree[cur].cnt[2];
	tree[cur].cnt[2] = tree[cur].cnt[1];
	tree[cur].cnt[1] = tree[cur].cnt[0];
	tree[cur].cnt[0] = tmp;
}

void update_child(int cur,int left,int right){
	tree[left].prop += tree[cur].prop;
	tree[right].prop += tree[cur].prop;
	int rotate  = tree[cur].prop%3;
	for(int s = 0;s<rotate;s++){
		update_prop(left);
		update_prop(right);
	}
	tree[cur].prop = 0;
}

void update_tree(int cur,int Start,int End,int u,int v){
    if(Start == u && End == v){
    	tree[cur].prop += 1;
    	update_prop(cur);
        return;
    }
    int left = cur*2;
    int right = left+1;
    int mid = (Start+End)/2;

    if(tree[cur].prop != 0){ //If prop exist then we add that to his child and make his one to 0;
		update_child(cur,left,right);
	}

    if(v <= mid){
    	update_tree(left,Start,mid,u,v);
    }else if(u > mid){
    	update_tree(right,mid+1,End,u,v);
    }else{
    	update_tree(left,Start,mid,u,mid);
    	update_tree(right,mid+1,End,mid+1,v);
    }
    tree[cur].cnt[0] = tree[left].cnt[0] + tree[right].cnt[0];
    tree[cur].cnt[1] = tree[left].cnt[1] + tree[right].cnt[1];
    tree[cur].cnt[2] = tree[left].cnt[2] + tree[right].cnt[2];
}

int tree_query(int cur,int Start,int End,int u,int v){
    if(Start == u && End == v){
    	return tree[cur].cnt[0];
    }
    int left = cur*2;
    int right = left+1;
    int mid = (Start+End)/2;
    if(tree[cur].prop != 0){ //If prop exist then we add that to his child and make his one to 0;
    	update_child(cur,left,right);
	}
    if(v <= mid){
		return tree_query(left,Start,mid,u,v);
	}else if(u > mid){
		return tree_query(right,mid+1,End,u,v);
	}else{
		return tree_query(left,Start,mid,u,mid) + tree_query(right,mid+1,End,mid+1,v);
	}
}

int main() {
    int N,Q,u,v,type;
	scanf("%d %d",&N,&Q);
	build_tree(1,1,N);
	for(int i = 1;i<=Q;i++){
		scanf("%d",&type);
		if(type == 0){
			scanf("%d %d",&u,&v);
			u++;v++;
			update_tree(1,1,N,u,v);
		}else{
			scanf("%d %d",&u,&v);
			u++;v++;
			int sum = tree_query(1,1,N,u,v);
			printf("%d\n",sum);
		}
	}
    return 0;
}
