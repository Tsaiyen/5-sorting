for i in $(seq 10 30)                                                                                                                                                                                      
do
    for time in $(seq 1 10)
    do  
        ./main_.exe $i dutchflagresult.csv 
    done    
done

