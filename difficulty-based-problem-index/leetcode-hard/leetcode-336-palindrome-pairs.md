# Leetcode 336 Palindrome Pairs

## Problem Statement

[https://leetcode.com/problems/palindrome-pairs/](https://leetcode.com/problems/palindrome-pairs/)

Given a list of **unique** words, return all the pairs of the **distinct** indices `(i, j)` in the given list, so that the concatenation of the two words `words[i] + words[j]` is a palindrome.

**Example 1:**

```text
Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
```

**Example 2:**

```text
Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
```

**Example 3:**

```text
Input: words = ["a",""]
Output: [[0,1],[1,0]]
```

**Constraints:**

* `1 <= words.length <= 5000`
* `0 <= words[i].length <= 300`
* `words[i]` consists of lower-case English letters.

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); i++)
        {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            mp[temp] = i;
        }
        
        for(int i = 0; i < words.size(); i++)
        {
            // For empty string handling
            if(mp.count("") && !words[i].empty() && is_palindrome(words[i]))
                result.push_back({i, mp[""]});
            
            string left, right;
            for(int j = 0; j < words[i].size(); j++)
            {
                left.push_back(words[i][j]);
                right = words[i].substr(j+1);
                if(mp.count(left) && mp[left] != i && is_palindrome(right))
                    result.push_back({i, mp[left]});
                if(mp.count(right) && mp[right] != i && is_palindrome(left))
                    result.push_back({mp[right], i});
            }
        }
        return result;
    }
    
    bool is_palindrome(const string &s) const
    {
        const int n = s.size();
        for(int i = 0 ; i < n/2; i++)
            if(s[i] != s[n-1-i])
                return false;
        return true;
    }
};
```

```cpp
Testcase:
["aehadfcgjd","dggd","fbaechf","aeij","afdjcffahef","gji","jghedhciggehhaf","cjaibcjbbfdbcdbjhgi","eddaiadgagdg","ihiidcjgbiib","ehbagejabjj","efedgbifcddici","bhgdeccihicchhfbedhh","hcggidd","fiahbdeceehh","diicddbficeed","fbbiicgib","b","ffjheahhgjefccedbj","jajh","cfbbdccjafdgfgci","e","fjggcagbcehic","hiah","jegacfbhebffi","caagbjdihcicijgbgbaj","jicieafigddabcfcaic","chhabfhiifid","jdbjiifadidh","ejcbhgdafigf","iejjjaibggdedfjaj","bjefgieghii","fejgcjjddecc","hjje","ihifgaagijge","eaaaeceaaeghegbi","gageeafaijfij","bd","icicfcjieiajgjjaebha","cbhgjaajiffej","ggegc","iciiie","ccjcjagcffcgcc","ahagibgjfcdehjigge","fcjbdjdhicchfh","faficchahhiaedjfcbh","gagigebeehjfeahfegf","feiffehcfjhef","ejcije","iggabc","aagfjbbbeej","eghdfcaaihcfjhfgehj","fjcjfediddbd","ihjed","ffigjdjjdaicdbdcjd","jjdgchjgfbcjcdi","jjgeijdjjefghhbibidj","jhdfgafjiajhjgg","bhdjdcjfihefiecaie","jcceg","jgciiabjfeeifcfijia","jgdbcgagigadeghbgfe","bggchaeiiceigcifa","eehfa","jceaecbeghbhagga","hjbchidajafei","dg","jbabfgjcdibaibfie","bhbae","ehdfa","jjfchiageajcbdddibjb","aacccgfiddfg","ihjbffbdgbhd","hei","gaaabebdjbddggeecjf","idjgaebj","dfjfcjj","fabfdhhfbdghf","aehfjcafjfeddaad","bhccbfahdf","cedidajihbecjddbgacd","bicghjecceggdi","hjegad","dhfbjacdfhaeigbj","jjiefjcajijfhicccg","a","cigjh","gc","eagbaabh","fce","hhccihbjgcdjj","gb","ebi","efgcadecaeihbae","edbbbhbicicahhegabcd","aa","dabijjafaae","ddiifcbdh","haihcheei","ada","jdfjefifijgdhji","gcfahaiifc","hibgjd","eaeighge","hcehb","chaejcdeih","afajgejhjcdg","ajgfedfgaiejbhcidh","d","abjgiiahhcijfedggb","hdgh","dafbicjejihicd","affchhbfadhbdjfa","dgjfejfgecbafbc","daechgce","jfbgfegdgchbheaiief","aedacaafddcaeidccj","bjijheeibeecaeg","gjjfdeeid","gafbaeh","dbjcdcibeefaejeb","dbgaaicc","fffjiejgaeebhje","chfaeeecgjjiefhcja","cgiihifbh","hfghadagigahd","aifjghhjddjig","eejehfifigdcf","jacbaeahediaecigg","adejhcbfgjjfbdaehicd","faafihfbcdhdeh","eadacabjabadgeii","hafhddadbehdajicij","cjcifahe","bgjchgdeffdg","bfhhiaacdccfiejej","aecfbb","cdjbaiiabcicibb","ddaeiai","cgfbeija","ffiad","dedbcbg","ecafahehichagc","dhaigigjbgijfag","ffedfejfhd","fijcbi","f","gedchcbighdf","ebhijggcdfacjhjcg","gbia","djidbdijdeciiadhh","bbgiihfbfdbdjc","ddhiddbeaeeajijbgdc","fghhhehba","gedgjjcjdcegageebbdh","ci","idja","ebadafbeccbhafgigdc","agcgejedaheabidifd","fdfdbgfddciaaegdf","ce","bhhiciihfaehjhhjb","ba","afbejcgjdeiaah","fefcbj","jbbfeiaechadafeg","gg","facihaif","idjafcehhicecigfj","df","hidccjebheiffcih","degdcjbgadjfahde","dacjbbejggjgcffa","jiefichbgf","cfddeb","agcjchi","de","ghhjjfgihahaibdbcf","edjbgd","fig","aagdjgebcfbbfaebh","ejjc","eiejegjhcjgabiejdihe","fjedcfddcebghagdfg","igdec","jfihddbcbjacighbdhfa","ggca","idhbaiiieg","idiec","fajhdcfhegefdiggjg","cfcjccbeccjjagi","eai","gbiehjiidcfiehf","adgachabh","bidcj","fjgejddfhffb","cbfhheaabiej","hhjibjdgih","ifhc","gbcfdgecdibha","hgecddf","jgeaafgdebf","ddgcbffh","dbabahgjgah","ijbhcf","bgjbeddbcejch","efdhffc","ffcbfcecejjbbggdajj","cibehhdgedbjh","chaggdiiiig","ibdefjghjbbifdfhbd","cfhhgebadj","hfdcahffacbciciiij","iaheghddfgcfjejh","gaehjbhdefgdgibcgghf","dgiahjf","cfcjedjgbeejhgeaag","hjbihc","egce","bjjbdjccibi","fejhbegibjjb","fbaahgcjbdfhhcjjedgb","ibeddhjac","cjiaciijaefe","fggjibfieg","dgbeidfbgjiaih","iffdgbhb","ddahagbgh","cejigjdhhfhfb","gachicaaiacabbggea","ccbibi","jidfaachibbijg","afbcbdbaihiggjjh","efbh","ffgfghehji","ifiibcjeggeff","fjhhahiifiid","dcfbghjfh","aicgcbegefjigci","ggffagcejaeafjjgf","dbgdif","cabhfghcjjah","fiie","djhfhidebajchcb","hhe","dbacbebfgjccf","ebjfefbfjcaaicaab","ii","cjhfiaieaccfefjecf","habii","gajjgggg","hbiccfhfcdgecdidb","jdjjjahaigcde","hedfjhhgi","hhjfg","acchchgcb","jhjgeidf","eb","gfbbgigja","fidhhii","ebdagjfcedagb","jjjhgcehijhefjjdgjec","dcjad","cedheeedjacj","acgjfdee","jcbabagjfgjhcfij","dcicabf","fedejjheffidjagagedc","cjbjbgjafgegbje","gceb","fcfaacbfjjfhbf","bgcifffcbibjhbedecef","jbhefgf","ie","ifaahjjbc","bgcjbbbbahgeiaebfj","ijefggicbegbae","iacefjadbefb","edih","jjdcbdiidaajdjd","c","biaedbdagfgjibih","jahacahhj","ffee","jacce","ddggcijfbhhcgbid","cfedbfchdjjcjeggb","ijdcfdaih","aedfgfiadhac","iajgaiedejgj","gjehfiidahhcg","afedihihhcbffaafg","caejibdfcacad","fhafhcggb","bdgehaehfheddgach","jciig","adhcdiicgbhdbh","jfbeeefaddecccahiig","aabidegcj","ifigacaif","ejeadbdjeafa","eaabfijajchggfiibchj","fgejgcigjgihheiejf","cgccdjchaa","igeihfjaiaeh","gejhjeffaciegbdfib","aaab","gbgiaha","bjaafffdefgiegadidha","giffiabfdfebihjjcij","adhd","gchfahg","hai","ijbbabicgdhhjaabhf","gdhgdbb","fddeg","idcibjd","gchehefigjhbcafgfe","iagcg","hcciidhihcfaihhacab","cdhgbheidi","igi","dacdcedda","dbceabdfh","gcb","ah","jcefahhabaf","bccjgfjfciihif","ejigebcfeafa","h","chd","jdgfieheehcacbibbbcd","gigihdjfbbdi","cahjicihahfeiffjbggi","adaii","gigaggcb","iggebfhhjciaejb","cbbbihgf","cfhbjgbjffejciidfbi","gegegij","fegdfd","dfeie","i","agajhaijafici","hbgeh","hfdfdjj","jbgihjgdbhb","beeiidefega","fhgaichjjidfchhcggf","bcchhhbefad","fdahjfebgdbjaicaaj","bfihjidfggh","aabbfdgcd","fjhafciifgb","hidc","aeccbghajg","dhcff","hebjfhjbgfhdfh","acificadgjjcfbaha","dajiccafjgbiijg","dahbdgbiihedjdegie","fjjjgjjdab","ehcgecjfhi","cebhajji","chbhahgbfigbaib","hcedgdcicg","cadcd","fciede","ggdiheh","aaehgajjh","efaceafccgjegddg","hjf","aehdfdih","hdeac","ffcfb","bbjghdhjafa","aafj","hcijaegjhh","jhdfjehdfgh","bajcgffefjjjdfgjidee","ebdhfbidgediaebbfj","fcegafgcieg","hif","bfjccefde","jc","djbjbdi","bfifcgh","jihjgg","bdgbechfheefacjj","dbhgaefbceg","ibcbhihbbecjcgbcd","egef","hfibdjjbfgb","bbjjijdcbffg","ehebj","dbeagih","egjiejgbgjgcejde","fffghecbhcije","bfgbjejjbifdgb","idbbjejejigafggjbah","cbe","jbgfiaighgfjfb","bchhbjghdbfcbjcffjh","chichbgbdgf","bgicedihegi","abdjgjebfdbgaghjec","ecfb","aeieeefgeahjieead","ejjibeihbbjhcacbif","gigfabfbidjigdibg","chccicib","gjgiedgahhdfeaj","fibjjiebbgdibcghg","gcaccbiii","hhfbbijffgfjcej","icfcjeebjagjhefhaeif","ffeeajdhdaeccj","bcecjhdjidehhbcccae","eeefh","bjeadaaddfihbcfahfhe","dccj","ieehjeigifj","hacchebgcdcbgcdbhhh","jeg","degbjejaggfcbfggfbce","aefdjfggjjeefbee","ca","dgbdeeh","jaeajdaee","ebibgedfjiibbjahbfad","jcgbicjdefi","icegfabbfdbei","jfhdhicc","igageijigjccjghb","cjgeigfcddad","cbhiadagggjeif","hgbejfgaiabfcefjb","adbigjjaijgihd","jgcijhcfgebbiii","iccec","adceichfcejabeeghjfj","agedcdbda","chfjiidjiab","bcabhghigegfbh","ih","idaacijbdhcdaccbgj","fi","eedcga","gbececjcichfe","eejcjjdiacja","bhedjagbhaehiejbhid","bhj","fehbcbcdefihj","icbifhdddjhh","ahdjfgchgci","g","ifa","fcdbcefe","hdd","jefjaihgjjddgcbehad","jhbi","jdicgjhhjd","gegdihbccgcbb","jeecichjcd","ahe","ahgaicdgfci","bdcdadiagdgbi","fejdbjbhic","aic","ahcadadcjhiagghbij","dca","cacjjejfdjbjhibg","ibicfaedbfcdbhjg","gdjifgfbadjdbhjbiie","cffgfdfabdhfchbbbbd","heecj","icbfabgbihaghhdch","bbgciagjadgajia","jghj","afdgegihghfdcbccda","igfhfhecijabe","hbaaahi","cidgagafhj","ijeabfjjiaiaeegcga","gbe","jbjiicdbeggehcbhjdf","cciihddhggjdjihbhj","cfgbahbdb","jbahg","eecjce","bggdbjbdgegbhjfi","dfbfeagbhfadbd","jhcajdjefcdgefhjdea","hcdcabaahgjjcgia","aaaaeggi","egabjhaa","aaafcidifejjededgcc","ceacbedgdhfibgbcfj","fjbejchhigcecfbie","hibagcddghjgcj","jagegfjdcffdfcbiagcc","ghacicaejjdcee","jgcec","did","edaijdghcfcfaggbeccd","jdfdhcbiigehfhhggjb","dfbfa","bbh","jegbhighafa","hdbhb","fhegijafbijb","hdbciibibhcj","gicjddbafgadgdh","bjcfa","dcejeb","cbjbebijc","gjaihjbjcjahaebhdeb","gahahcedbh","hia","ehedaheb","cccb","dijdfchc","cfcigjeddcbihhia","ehfcfj","adijbihcajhcd","fhh","dehdcb","jibei","feahbjehbidhfhc","headgfgagbeaghjb","hcjj","gbejadijcefdeidc","jgjed","bcciige","eafihhbgd","cfdgfh","hfefddcb","ebhbfbhbcjehejidhgi","cgejgaiiebdfhi","fbjgicjjghgjdbd","gidgiabcbhdh","eaajhjhedfbch","aciigeajchjafcaigfc","baihfdji","aff","fdehgjaie","hfic","ac","dgccdbdidccagf","ecii","badcchggehcfei","hgcdagdbehfchjigjgef","cejci","fgbdbhabijcbg","jcefcib","ijcghbi","jgbdjieccdj","jhibdcedajhjd","bfj","hh","edabhgeffbhee","hfddecfbbddchfj","jajgfahadfhfaajgceed","ji","cgi","ijjbeahefacibajdhf","jcfbch","addfibhhdf","dcecfdeaibeje","ifiea","bdhhdbfd","cebbbfbeeaehdbahdih","aaci","feb","giedgdbjdcecghafic","jhigcecb","ibdcgbbda","bhechgfij","ggjiehhjgi","iffafihe","chfec","aabhce","dhih","cebcehbbfeeibj","faceghabagdjdejbc","jcejgfbbdbid","ccdja","hgiddiif","ahh","cbcag","beifib","jdbbgjbagfhaiecje","ihgbe","gdhdgehjbe","bahd","fjgjhbjdjdf","agacddiaea","cfagbjchfbgejbjcbia","fgiffi","caddidbhfadcafjgfijb","dahaifgb","jbedcadhcacbadfcha","hceaaebjiijai","feife","dgbaeffgfddabfha","ihjjcjcfbjj","jcdbjja","hhggg","jaej","bcjfhf","hfeccgf","fiehhebajjigajc","dejid","cfcgicdcbafej","gahf","j","gieebagjiegg","hegce","gfghecdaecgffga","gaijefhi","fajagegficghibhdae","jcjghaib","eiacaece","ciicd","fggbgjhfaf","jifajcjedhiifga","chhejif","efcdbeadcebjdfe","ha","cfidiahdeidbgd","igbdbb","eddaijgafhdb","jacgfi","fbgjihci","gcaegbgcac","jagjbhdhadadbdcef","edgahaej","efabjjefiig","dijhdgijcgfhfe","fbabcigbhfbbcciagi","ibidjgfb","giajhdcahiccaibbji","bbjjibhgbdj","hbdhjecihih","fjfccige","diebecfdebcje","hg","igij","cfjgeaabedgbb","afgehhbhbe","ij","jecbgjffhbbihhjjeec","af","dbbgaed","cjhiaic","hhdcaegbgfhf","ihgejhiiaifi","bhahiigjeeaehgggead","hdbfhjbgdccd","iedhgj","baaefaiiec","bdfcb","gibgjjcjhacgfehddigj","hhgg","hcifejid","ghejafbjejba","jecidjj","acggchgigijhi","fbjgbeejgjjhfhjifd","ieehcdafeaidfaeh","fjeddiedcb","bbca","ea","jhefgbhhcajce","aghhe","hejhiidgbbfjeafd","cafiggdiaegddbb","echiii","ehiafhhagigcc","hbehjcgicee","gdj","fgh","bhjicjadcehcgbbe","ffbdgafdijbibgfachei","gbgdaajhei","ghceeed","dgejhcbgcgg","fcchc","jchdajhhejbd","jie","idddbhhbhiijjde","hchic","ibjbdajegdcib","fhjabhagaieahichcha","bfcbecefg","iehej","ifebddafdideeegj","bhigafci","ehageeaihhejehce","jfd","cehe","hjgg","aj","chdcddfdbchjadechaa","dibdfagfheei","aicdagfhbi","agceg","efeaaedfachgdjhcihai","dicgjdiaf","bcjcffcbhegceibeb"]
```



