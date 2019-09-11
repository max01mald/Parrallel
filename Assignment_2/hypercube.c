/*procedure HYPERCUBE QUICKSORT (B, n) 
begin
	id := process’s label;
	for i:=1 to d do 
	begin
		x := pivot;
		partition B into B1 and B2 such that B1 ≤ x < B2; 
		
		if ith bit is 0 then
		begin
			send B2 to the process along the ith communication link;
			C := subsequence received along the ith communication link; 
			B := B1 ∪ C;
		end if 
		else
			send B1 to the process along the ith communication link;
			C := subsequence received along the ith communication link; 
			B := B2 ∪ C;
		end else 
	end for
	sort B using sequential quicksort; 
end HYPERCUBE QUICKSORT*/

