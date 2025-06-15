// if(k >=a) {
//         long long c1  = (k - a) / x + 1;
//         long long rk = k - c1 * x;
//         long long c2 = 0;
//         if (rk >=b){
//             c2 = (rk -b) / y + 1;
//         }
//         ans1 = c1 + c2;
//     }

//     long long ans2 =0;

    
//     if(k >=b) {
//         long long c2  = (k - b) / y + 1;
//         long long rk = k - c2 * y;
//         long long c1 = 0;
//         if (rk >=a){
//             c1 = (rk -a) / x + 1;
//         }
//         ans1 = c1 + c2;
//     }
//     cout<< max(ans1, ans2)<<"\n";

// }




// long long k, a, b, x, y;
//         cin>> k >> a >> b >> x >> y;

//         long long ans = 0;

//         if (a < b || (a==b && x < y)){
//             while(k >= a)
//             {
//                 long long count = (k - a) / x + 1;
//                 ans +=count; 
//                 k -= count * x;
//             }
//             while (k >= b) {
//                 long long count = (k - b) / y + 1;
//                 ans += count;
//                 k -= count * y;
//             }
//         }
//         else{
//             while(k >=b){
//                 long long count = (k - b) / y + 1;
//                 ans += count; 
//                 k -= count * y;

//             }
//             while(k >= a)
//             {
//                 long long count = (k - a) / x + 1;
//                 ans +=count; 
//                 k -= count * x;
//             }
//         }

//     cout << ans <<"\n";
//     }
//     return 0;
 // while(k > 0)
        // {
        //     if (k >=a,b){
        //         k-=min(x,y);
        //     }
        //     else{
        //         k -= max(x,y);
        //     }
        //     count++;
        // }
        // cout<<count<<"\n";
        // if(k > a || k > b){
        //     while(k!=0){
        //         k-=max(x,y);
        //         count++;
        //         if(k<a){
        //             k-=min(x,y);
        //             count ++;
        //         }
        //         if(k<0){
        //             break;
        //         }         
        //     }
        //     cout << count << "\n";
        // }
        // else{
        //     cout << 0 <<"\n";
        // }




        
    //     while(true){

    //         bool cook_type1 = (k >= a);
    //         bool cook_type2 = (k >= b);

    //         if(!cook_type1 && !cook_type2){
    //             break;
    //         }
    //         long long curr;
    //         long long next;

    //         if(cook_type1 && cook_type2){
    //             // if(x <=y){
    //             //     k -= x;
    //             // }
    //             // else{
    //             //     k -= y;
    //             // }
    //             curr = min(x,y);
    //             next = max(x,y);
    //         }

    //         else if(cook_type1){
    //             // k-=x;
    //             curr = x;
    //             next = a;
    //         }

    //         // else if(cook_type2){
    //         //     k-= y;
    //         // }
    //         else{
    //             curr = y;
    //             next = b;
    //         }

    //         long long jump = 0;
            
    //         if(k > next){
    //             jump = (k - next + curr)  / curr + 1;
    //         }
    //         else{
    //             next = 1;
    //         }
    //         count += jump;
    //         k -= jump * curr;
    //     }
    //     cout<<count<<"\n";  
    // }