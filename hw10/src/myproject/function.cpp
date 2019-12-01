

std::pair<float, float> turn_left(std::pair<float, float> obj){
    std::pair<float, float> ans;
    return std::make_pair(-obj.second, obj.first);
}