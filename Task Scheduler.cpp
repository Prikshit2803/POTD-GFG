//INTUITION--

//FIND THE CHAR WITH MAX FREQ AND ALSO FIND THE NO. OF CHARS WITH MAX FREQ

// N = 12
// K = 2
// task[ ] = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}

// yaha Idle time 2 hai to hum Max freq wale task ko is way me arrange karenge ki idle time ke pehle same task repeat Na ho or baki ki remaining spaces me humare bache huye task perform ho jayenge jaha tasks khatam hoge waha idle time fill ho jayega 

// A _ _ A _ _ A _ _ A _ _ A _ _ A = 16 places

// Agar yaha koi or task hota jiski freq maxi freq wale task ke equal hoti to hum usko bhi last me add kar dete jaisa pehle test case me hua

// task[ ] = {'A', 'A', 'A', 'B', 'B', 'B'}

// A B _ A B _ A B

// yaha B ki freq max ke equal thi isliye usko bhi add karna padega last me

// main logic:

// res = (maxfreq-1)*(k+1) + (total elements with max freq)= (6-1)*(2+1) + 1 = 16

// if(N > res) then we will return N because we can easily arrange them without being idle







class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        vector<int> freq(26,0);
        
        int nm=0; // to measure number of elements with max freq
        
        for(int i=0;i<N;i++){
            freq[tasks[i]-'A']++;
            //cout<<freq[tasks[i]-'A']<<".  ";
        }
        
        
        int maxfreq= *max_element(freq.begin(),freq.end());
        
        for(auto it : freq){
            //if(freq[it]==maxfreq)
            if(it==maxfreq)
            nm++;
        }
        
        int res = (maxfreq-1)*(K+1) + nm;
        return max(res,N); // this because if res<N  we can arrange without idle easily
    }
};

// Similar approach with Hashmap
class Solution {

  public:

    int leastInterval(int N, int K, vector<char> &tasks) {

        unordered_map<char, int> mp;

        int count = 0;

        for (auto e : tasks) {

            mp[e]++;

            count = max(count, mp[e]);

        }

 

        int ans = (count - 1) * (K + 1);

        for (auto e : mp)

            if (e.second == count) ans++;

        return max((int)tasks.size(), ans);

    }

};
