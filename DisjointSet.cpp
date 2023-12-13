#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank , parent ,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i <= n ; i++){
            parent[i]=i;   //same parent for same index
            size[i]=1;     //size of all vertices will be one at stating
        }
    }
    
    int findUPar(int node){ //find Ultimate parent
        if(node==parent[node])
                return node;
        else
            return parent[node]=findUPar(parent[node]);
            //path compresion is here we don't have to visit the whole vertices of graph to find it's parent
    }

    void unionByRank(int u , int v){
        int ulp_u = findUPar(u); //ultimate parent of u
        int ulp_v = findUPar(v); //ultimate parent of v
        if(ulp_u == ulp_v) return;     //if parent is same then simply return
        if(rank[ulp_u] < rank[ulp_v]){  //if ul_parent of u is less than v then 
        
        parent[ulp_u] = ulp_v;      //add the u to v becuase v is large and make prant of u to v

        }
        else if(rank[ulp_v] < rank[u]){ 
            parent[ulp_v] = ulp_u ;      //opposite of above
        }

        else{ //if ultimate parent of both the vertices are same then make parent to any and add them 

            parent[ulp_v] = ulp_u ;   // here we are making parent u
            rank[ulp_u]++;            //rank will increase

        }
            
    }

    void unionBySize(int u , int v){
        int ulp_u = findUPar(u);    //ultimate parent of u
        int ulp_v = findUPar(v);     //ultimate parent of v
        if(ulp_u == ulp_v) return;     //if parent is same then simply return

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];  //size is getting attached to ulp_v then it will increase by size of ulp_u
        }
        else{      //if equal size
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];  //anyone can be parent and here ulp_u beacoming parent so size of ulp_v getting attached to ulp_u and increased by size of ulp_v
        }
    }

};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    //if 3 and 7 same or not
    
    cout<<"Union By Rank"<<endl;

    if(ds.findUPar(3)==ds.findUPar(7)){   //having same set or not means both belongs to same parent or not
        cout<<"Same\n"; 
    }
    else    cout<<"Not same\n";

    ds.unionByRank(3,6); 

    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"Same\n";
    }
    else    cout<<"Not same\n";


    cout<<"Union By Size"<<endl;
    DisjointSet ds2(7);
    ds2.unionBySize(1,2);
    ds2.unionBySize(2,3);
    ds2.unionBySize(4,5);
    ds2.unionBySize(6,7);
    ds2.unionBySize(5,6);

    if(ds2.findUPar(3)==ds2.findUPar(7)){   //having same set or not means both belongs to same parent or not
        cout<<"Same\n"; 
    }
    else    cout<<"Not same\n";

    ds2.unionBySize(3,6); 

    if(ds2.findUPar(3)==ds2.findUPar(7)){
        cout<<"Same\n";
    }
    else    cout<<"Not same\n";
    return 0;
}


// Refrence => https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/