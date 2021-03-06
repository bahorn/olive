#ifndef SUMSAMPLES_H
#define SUMSAMPLES_H

#include <QFloat16>
#include <QVector>

class SampleSummer {
public:
  struct Sum {
    Sum();

    qfloat16 min;
    qfloat16 max;
  };

  // FIXME: Move to config
  static const int kSumSampleRate;

  static QVector<Sum> SumSamples(const float* samples, int nb_samples, int nb_channels);
  static QVector<Sum> SumSamples(const qfloat16* samples, int nb_samples, int nb_channels);

  static QVector<Sum> ReSumSamples(const SampleSummer::Sum* samples, int nb_samples, int nb_channels);

private:
  template <typename T>
  static QVector<Sum> SumSamplesInternal(const T* samples, int nb_samples, int nb_channels);

};

#endif // SUMSAMPLES_H
