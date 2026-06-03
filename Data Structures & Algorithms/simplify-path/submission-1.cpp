class Solution {
public:
    string simplifyPath(string path) {
        path+='/'; // Adding at the end to maintain logic for the last dir/file
        stack<string> actualpath; // can use queue but stack helps with /../
        int i=0;
        string dirfile;
        while (i<path.size()) { // decoding
            if (path[i]=='/' and dirfile=="..") { // ..
                if (!actualpath.empty()) actualpath.pop();
                dirfile="";
            } else if (path[i]=='/' and dirfile==".") dirfile=""; // . current dir
            else if (path[i]=='/' and dirfile!="") { // general
                actualpath.push(dirfile);
                dirfile = "";
            } else if (path[i]=='/') ; // repeated /
            else dirfile+=path[i];
            i++;
        }
        if (dirfile!="") actualpath.push(dirfile);
        string simplepath;
        while (!actualpath.empty()){
            simplepath=actualpath.top()+simplepath;
            simplepath='/'+simplepath;
            actualpath.pop();
        }
        if (simplepath=="") simplepath='/'; // edge case
        return simplepath;
    }
};