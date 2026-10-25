#include<limits>
#include<algorithm>
#include<vector>
#include<iostream>

int  mochila(const std::vector<int>& p, const std::vector<int>& b,  int m, std::vector<int>& s) {
	int n= p.size();
	std::vector<std::vector<int>> g(n+1, std::vector<int>(m + 1, 0));
	
	for (int i=1;i<=n;i++){
		for(int c=1;c<=m;c++){
			if(p[i-1]>c){
				g[i][c]=g[i-1][c];
			}else{
				g[i][c]=std::max(g[i-1][c],g[i-1][c-p[i-1]]+b[i-1]);
			}
		}
	}

	s.assign(n, 0);
	int i = n;
    int c = m;

	while (i>0 && c>0) {
        if (g[i][c]!=g[i-1][c]){
				s[i-1]=1;
				c=c-p[i-1];
        }
		i=i-1;
    }

return g[n][m];
}

int main(){

std::vector<int> p = {9, 6, 5};
std::vector<int> b = {38, 40, 24};
int m = 15;
std::vector<int> s_mochila;

int beneficio_max = mochila(p, b, m, s_mochila);
std::cout << "Capacidad maxima: " << m << "\n";
std::cout << "Elementos elegidos (1 =Si, 0 = No):\n";
for (int i = 0; i < p.size(); i++) {
    std::cout << "Elemento " << i << " (peso " << p[i] << ", beneficio " << b[i] << "): " << s_mochila[i] << "\n";
}
std::cout << "Beneficio maximo: " << beneficio_max << std::endl;

}
