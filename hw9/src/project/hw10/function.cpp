

std::pair<float, float> turn(std::pair<float, float> obj, int angle){
    std::pair<float, float> ans;
    switch (angle)
    {
        case 90:
            return std::make_pair(-obj.second, obj.first);
        case 180:
            return std::make_pair(-obj.first, -obj.second);
        case 270:
            return std::make_pair(obj.second, -obj.first);
        default:
            throw(std::runtime_error("wrong angle"));
    }
    
}