for i in $(seq 10 29)                                                                                                                                                                                      
do
    for time in $(seq 1 10)
    do  
        ./main_.exe $i lomutoresult.csv 
    done    
done

