void setMapDemo() {
    setDemo();
    mapDemo();
}

void setDemo() {
    setDemoSET();
    setDemoMULTISET();
}

void setDemoSET() {
    SET set = {1, 2, 2, 3, 5};
    set.insert(2);
    set.insert(4);
    set.insert(10);
    set.erase(3);
    set.erase(11);
    int count_something = set.count(20); // may be used as "contains" in C++20
    auto iter_2 = set.find(2);
    set.erase(set.begin(), iter_2);

    for (auto element : set) cout << element << ' ';
    cout << endl;

    bool is_empty = set.empty();
    auto value_inserted = set.emplace(1);
    auto value = set.emplace(1);
    set.emplace(11);
    int set_size = set.size();
    auto lb = set.lower_bound(4); // element in set <= 4
    auto ub = set.upper_bound(4); // element in set > 4
    auto lb_min = set.lower_bound(0);
    set.merge((SET){100, 200, 300}); // C++17
    set.merge((MULTISET){100, 100, 100, 100, 20, 300}); // C++17
    set.clear();
}

void setDemoMULTISET() {
    MULTISET multiset = {1, 2, 2, 3, 5};
    multiset.insert(2);
    multiset.insert(4);
    multiset.insert(10);
//    multiset.erase(2);
    multiset.erase(3);
    multiset.erase(11);
    int count_1 = multiset.count(1);
    int count_2 = multiset.count(2);
    int count_20 = multiset.count(20);
    auto iter_4 = multiset.find(4);
    multiset.erase(multiset.begin(), iter_4);

    for (auto element : multiset) cout << element << ' ';
    cout << endl;

    bool is_empty = multiset.empty();
    auto value_inserted = multiset.emplace(1);
    auto value = multiset.emplace(1);
    multiset.emplace(11);
    int set_size = multiset.size();
    auto lb = multiset.lower_bound(1); // element in set <= 4
    auto ub = multiset.upper_bound(1); // element in set > 4
    multiset.merge((MULTISET){100, 100, 2, 2, 300}); // C++17
    multiset.merge((SET){11, 12, 13}); // C++17
    multiset.clear();
}

void mapDemo() {
    mapDemoMAP();
    mapDemoMULTIMAP();
}

void mapDemoMAP() {
    MAP map = {{1, 10.0}, {2, 20.0}, {3, 30.0}, {4, 40.0}};
    auto iter_2 = map.find(-1);
    float element_1 = map[1];
    float element_10 = map[10]; // appends pair 10: 0

    bool is_empty = map.empty();
    int map_size = map.size();
    map.insert({5, 50.0});
    map.insert({5, 500.0});
    auto iter_1 = map.emplace(5, 50.0);
    map.emplace(5, -50.0);
    auto equal_range_1 = map.equal_range(1);
    auto equal_range_m1 = map.equal_range(-1);
    auto equal_range_3 = map.equal_range(3);
    auto lb = map.lower_bound(3);
    auto ub = map.upper_bound(3);
    auto find_1 = map.find(1);
    auto find_3 = map.find(3);
    auto find_1000 = map.find(1000);
    map.erase(find_1, find_3);
    map.merge((MAP){{111, 1110.0}});
    map.merge((MULTIMAP){{111, 1110.0}, {111, 1111.1}});
    map[111] = 111.0;
    map.clear();
}

void mapDemoMULTIMAP() {
    MULTIMAP multimap = {{1, 10.0}, {2, 20.0}, {3, 30.0}, {4, 40.0}, {1, 100.0}, {2, 200.0}, {3, 300.0}};
    int count_1 = multimap.count(1);
    int count_4 = multimap.count(4);

    bool is_empty = multimap.empty();
    int map_size = multimap.size();
    multimap.insert({5, 50.0});
    multimap.insert({5, 500.0});
    auto iter_1 = multimap.emplace(5, 50.0);
    multimap.emplace(5, -50.0);
    auto equal_range_1 = multimap.equal_range(1);
    auto equal_range_m1 = multimap.equal_range(-1);
    auto equal_range_3 = multimap.equal_range(3);
    auto lb = multimap.lower_bound(3);
    auto ub = multimap.upper_bound(3);
    auto find_1 = multimap.find(1);
    auto find_3 = multimap.find(3);
    auto find_1000 = multimap.find(1000);
    multimap.erase(find_1, find_3);
    multimap.merge((MAP){{111, 1110.0}});
    multimap.merge((MULTIMAP){{111, 1110.0}, {111, 1111.1}});
    multimap.clear();
}