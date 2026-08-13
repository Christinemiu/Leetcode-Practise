// 第1行：定义Solution类
class Solution {  
    
// 第2行：声明公共访问权限
public:  
    
    // 第3行：函数声明
    // vector<int> 表示返回值类型是整数数组
    // smallerNumbersThanCurrent 是函数名
    // (vector<int>& nums) 表示参数是一个整数数组的引用（避免拷贝，提高效率）
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        // 第4行：创建副本
        // sorted 会包含和nums完全相同的元素
        vector<int> sorted = nums;
        
        // 第5行：排序
        // 对sorted进行升序排列
        // 例如：{8,1,2,2,3} → {1,2,2,3,8}
        sort(sorted.begin(), sorted.end());
        
        // 第6行：创建哈希表
        // unordered_map 是哈希表实现，查找效率O(1)
        // 键是int（数字），值是int（该数字首次出现的位置）
        unordered_map<int, int> map;
        
        // 第7行：开始遍历排序后的数组
        for (int i = 0; i < sorted.size(); i++) {
            
            // 第8行：检查是否已存在
            // map.find(key) 返回迭代器
            // 如果找到，返回指向该元素的迭代器
            // 如果没找到，返回 map.end()
            if (map.find(sorted[i]) == map.end()) {
                
                // 第9行：记录首次出现位置
                // 因为数组已排序，第一次出现的位置就是比它小的数字个数
                // 例如：数字2第一次出现在索引1，说明有1个数字比2小
                map[sorted[i]] = i;
            }
            // 第10行：如果已存在，不做任何事（保证只记录第一次出现）
            // 这是大括号结束
        }
        // 第11行：for循环结束
        
        // 第12行：创建结果数组
        // 用于存储最终要返回的结果
        vector<int> arr;
        
        // 第13行：范围for循环
        // 语法：for (元素类型 变量名 : 容器)
        // 每次迭代，num会依次取nums中的每个元素
        for (int num : nums) {
            
            // 第14行：查询并添加
            // map[num] 会返回哈希表中键为num的值（即比num小的数字个数）
            // push_back() 将这个值添加到arr的末尾
            arr.push_back(map[num]);
        }
        // 第15行：for循环结束
        
        // 第16行：返回结果
        // 将计算好的arr返回给调用者
        return arr;
    }
    // 第17行：函数结束
};
// 第18行：类定义结束