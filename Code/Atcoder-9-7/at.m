sum = 0;
for i = 1:13
    sum = sum + mod(i, 13+1-i);
end
sum