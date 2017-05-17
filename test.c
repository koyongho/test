//테스트중
#include <stdio.h>
#define TEST 5

/*
 *  likely, unlikely()는 branch predition 역할을 수행함.
 *   이는 cpu pipeline을 보다 더 효율적으로 사용하기 위해 사용함.
 *    likely : 조건문이 true가 될 확률이 높은 조건문에서 사용
 *     unlikely : 조건문이 false가 될 확률이 높은 조건문에서 사용
 *      */
#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

int main(void)
{
	const int x = 3;
	int y = (unlikely(__builtin_constant_p (x)) ? (x) : -1);
	int z = (likely(__builtin_constant_p (TEST)) ? (TEST) : -1);
	char buf[256];
	sprintf(buf, "test : %d\n", y); 
	puts(buf);
	sprintf(buf, "test2 : %d\n", z); 
	puts(buf);
	return 0;
}

