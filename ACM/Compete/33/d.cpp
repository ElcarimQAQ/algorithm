bool line_make_point=(line a,line b,point &res){
    if(par(a,b))
        return false;
    double s1 =det(a.a - b.a,b.b - b.a);
    double s2 = det(a.b - b.a ,b.b-b.a);
    res = (s1*a.b - s2*a.a) /(s1 -s2);
    return true;
}