//
// file:			0002_check_incorrect_hashes.cpp
// created on:		2023 Aug 30
//

#include <simple_cpp_bcrypt/bcrypt.h>
#include <cinternal/unit_test.h>
#include <stddef.h>


struct SPassAndHash {
	const char* password;
	const char* hash;
};


// some incorrect passwords 
static const struct SPassAndHash  s_incorrectPairs[] = {
	{"Password1inc","$2a$12$kCqMi6/ICcWoNdpqT4Ly7ul5EwEUzZVRZsT0cxUq.cKQGcpGDJ.M."},
	{"Password2inc","$2a$12$kCqMi6/ICcWoNdpqT4Ly7uj7QNDFFHtJyQNyh.DvBYB9mCrlPDJ/u"},
	{"Password3inc","$2a$12$kCqMi6/ICcWoNdpqT4Ly7ui3ykUpWlivNE32DLjZEegkMdYR1B8hO"},
	{"Password4inc","$2a$12$kCqMi6/ICcWoNdpqT4Ly7uDSYGfrlUJ581NlyJCvtpdjpyqImZhie"},
	{"Password5inc","$2a$12$kCqMi6/ICcWoNdpqT4Ly7uE7XKR0iwQaakusWPVV3LoM9rXR9xmYi"}
};


TEST(f_0002_check_incorrect_hashes, t_0001)
{
	bool bComparision;
	size_t i;
	const size_t scunIncorrectsCount = sizeof(s_incorrectPairs) / sizeof(const struct SPassAndHash);

	for (i = 0; i < scunIncorrectsCount; ++i) {
		bComparision = SimpleCppBcryptVerify(s_incorrectPairs[i].password, s_incorrectPairs[i].hash);
		ASSERT_FALSE(bComparision);
	}
}
