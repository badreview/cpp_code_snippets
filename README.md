# cpp_code_snippets
the code snippets collection

sort custom data by lambda function
```c++
    std::vector<std::vector<int> > array;
    
    array.push_back({0, 5});
    array.push_back({3, 5});
    array.push_back({1, 5});
    array.push_back({2, 2});
    
    //ordered by item[1] ascending, and then item[0] descending
    std::sort(array.begin(), array.end(),[](const std::vector<int> &a, const std::vector<int> &b){
        return (a[1] < b[1]) || (a[1] == b[1] && a[0] > b[0]);
    });
    
```
result: [2, 2], [3, 5], [1, 5], [0, 5]


