module multiplexer (SW,KEY,X);
input [7:0] SW;  // Đầu vào công tắc (SW) 8 bit
input [2:0] KEY; // Đầu vào phím (KEY) 3 bit
output X;		  // Đầu ra X 1 bit

wire [7:0] Y; // Định nghĩa dây Y 8-bit để lưu các giá trị trung gian

// Y[0] sẽ sáng khi gạt nút SW[0] lên và không nhấn giữ 3 nút KEY[2:0]  
assign Y[0] = SW[0] & ~KEY[2] & ~KEY[1] & ~KEY[0]; 

// Y[1] sẽ sáng khi gạt nút SW[1] lên và nhấn giữ 1 nút KEY[0] = 1
assign Y[1] = SW[1] & ~KEY[2] & ~KEY[1] & KEY[0];

// Y[2] sẽ sáng khi gạt nút SW[2] lên và nhấn giữ 1 nút KEY[1] = 1
assign Y[2] = SW[2] & ~KEY[2] & KEY[1] & ~KEY[0];

// Y[3] sẽ sáng khi gạt nút SW[3] lên và nhấn giữ 2 nút KEY[1:0] = 1  
assign Y[3] = SW[3] & ~KEY[2] & KEY[1] & KEY[0];

// Y[4] sẽ sáng khi gạt nút SW[4] lên và nhấn giữ 1 nút KEY[2] = 1  
assign Y[4] = SW[4] & KEY[2] & ~KEY[1] & ~KEY[0];

// Y[5] sẽ sáng khi gạt nút SW[5] lên và nhấn giữ 2 nút (ở vị trí bit thứ 2 và bit thứ 0) = 1 
assign Y[5] = SW[5] & KEY[2] & ~KEY[1] & KEY[0];

// Y[6] sẽ sáng khi gạt nút SW[6] lên và nhấn giữ 2 nút KEY[2:1] = 1  
assign Y[6] = SW[6] & KEY[2] & KEY[1] & ~KEY[0];

// Y[7] sẽ sáng khi gạt nút SW[7] lên và nhấn giữ 2 nút KEY[2:0] = 1 (tức là đè 3 nút bấm KEY)  
assign Y[7] = SW[7] & KEY[2] & KEY[1] & KEY[0];

// Gán đầu ra X là kết quả OR của tất cả các bit Y, đầu ra X là 1 nếu có bất kỳ bit nào của Y là 1
assign X = Y[0] | Y[1] | Y[2] | Y[3] | Y[4] | Y[5] | Y[6] | Y[7] ;

endmodule // Kết thúc
