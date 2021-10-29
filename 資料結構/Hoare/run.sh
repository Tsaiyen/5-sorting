#for i in $(seq 10 29)                                                                                                                                                                                      
for i in 30
do
    for time in $(seq 1 10)
    do  
        ./main_.exe $i hoareresult.csv 
    done    
done

