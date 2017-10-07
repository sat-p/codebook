// Usage:
// f[0...N-1] and g[0..N-1] are numbers
// Want to compute the convolution h, defined by
// h[n] = sum of f[k]g[n-k] (k = 0, ..., N-1).
// Here, the index is cyclic; f[-1] = f[N-1], f[-2] = f[N-2], etc.
// Let F[0...N-1] be FFT(f), and similarly, define G and H.
// The convolution theorem says H[n] = F[n]G[n] (element-wise product).
// To compute h[] in O(N log N) time, do the following:
//   1. Compute F and G (pass dir = 1 as the argument).
//   2. Get H by element-wise multiplying F and G.
//   3. Get h by taking the inverse FFT (use dir = -1 as the argument)
//      and *dividing by N*. DO NOT FORGET THIS SCALING FACTOR.
// To compute an *acyclic* convolution, pad f and g to the right with zeroes.

typedef std::complex<double> cpx;

std::unordered_map<double, cpx> EXP_;

inline cpx EXP (const double theta)
{
    auto it = EXP_.find (theta);
    if (it != EXP_.end())
        return it->second;
    else
        return EXP_[theta] = cpx (cos (theta), sin (theta));
}

const double two_pi = 4 * acos(0);

// in:     input array
// out:    output array
// step:   {SET TO 1} (used internally)
// size:   length of the input/output {MUST BE A POWER OF 2}
// dir:    either plus or minus one (direction of the FFT)
// RESULT: out[k] = \sum_{j=0}^{size - 1} in[j] * exp(dir * 2pi * i * j * k / size)
inline void FFT(cpx *in, cpx *out, int step, int size, int dir)
{
  if(size < 1) return;
  if(size == 1)
  {
    out[0] = in[0];
    return;
  }
  const int size_2 = size >> 1;
  
  FFT(in, out, step << 1, size_2, dir);
  FFT(in + step, out + size_2, step << 1, size_2, dir);
  for(int i = 0 ; i < size_2 ; i++)
  {
    cpx even = out[i];
    cpx odd = out[i + size_2];
    
    const auto e = EXP(dir * two_pi * i / size);
    
    out[i] = even + e * odd;
    out[i + size_2] = even - e * odd;
  }
}