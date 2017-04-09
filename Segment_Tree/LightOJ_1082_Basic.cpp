#include<bits/stdc++.h>

using namespace std;

#define mx 100005
#define inf 1e7

int tree[mx*3],arr[mx];

void build_tree(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }

    int mid = (b+e)/2;

    int left = node*2;

    int right = node*2+1;

    build_tree(left,b,mid);
    build_tree(right,mid+1,e);

    tree[node] = min(tree[left],tree[right]);
}
int query_tree(int node, int b, int e, int i, int j)
{
    if(j<b||i>e)
        return inf;
    if(b>=i&&e<=j)
    {
        return tree[node];
    }

    int mid = (b+e)/2;

    int left = node*2;

    int right = node*2+1;

    int mn1 = query_tree(left,b,mid,i,j);
    int mn2 = query_tree(right,mid+1,e,i,j);

    return min(mn1,mn2);

}

int main()
{
    int test,cs=1;

    scanf("%d",&test);

    while(test--)
    {
        int N, Q;

        scanf("%d %d",&N,&Q);

        for(int i=1;i<=N;i++)
            scanf("%d",&arr[i]);

        build_tree(1,1,N);



        printf("Case %d:\n",cs++);

        while(Q--)
        {
            int i, j;
            scanf("%d %d",&i,&j);
            printf("%d\n",query_tree(1,1,N,i,j));
        }



    }
}
