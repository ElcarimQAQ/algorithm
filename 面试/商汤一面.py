nodelist="HOST-T-10-140-60-[1-2,4-5,119-120,188],HOST-T-10-140-70-192"

ip_ori = nodelist.split(',')

def trans(nodelist, s, e):
    str_list = nodelist[s+1:e].split(',')
    nums = []
    for str_now in str_list:
        nums.append(str_now.split('-'))
    return nums
   
ip_list = []
ip = ""
flag = True
for i, c in enumerate(nodelist):
    if c == '[':
        flag = False
        s = i
    if flag:
        ip += c
    if c == ']':
        e = i
        
ans  = trans(nodelist, s, e)
for num in ans:
    for i in num:
        print(num)
        ip_now = ip + str(i)
        ip_now.strip('[')
        ip_list.append(ip_now)
ip_list.append(ip_ori[-1])
print(ip_list)
        