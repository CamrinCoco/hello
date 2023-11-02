char rnaToProtein(const char *rna) {
  if(rna == NULL || strlen(rna) != 3) {
    return 0;
  }
  ProteinMap key = { "", '\0' };
  strcpy(key.trigram, rna);
  ProteinMap *match = bsearch(&key, pMap, NUM_TRIGRAMS, sizeof(ProteinMap), proteinMapComp);
  return (match == NULL) ? 0 : match->protein;

}
