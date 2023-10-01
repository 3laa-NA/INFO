for i in {1955..2016}; do
    mkdir -p /by_year/$i
    find 1001_Albums_You_Must_Hear_Before_You_Die -type f -name "*-*-$i*" -exec cp {} "by_year/$i" \;
done