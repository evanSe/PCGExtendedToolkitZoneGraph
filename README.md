![UE 5.8](https://img.shields.io/badge/UE-5.8-darkgreen)

<p align="center">
  <img src="https://github.com/Nebukam/PCGExElementsZoneGraph/blob/main/Resources/ZG_Logo.png" alt="PCGEx Logo">
</p>

<h1 align="center">PCGEx + ZoneGraph</h1>

<p align="center">
  <strong>Generate ZoneGraph data for AI navigation from PCGEx clusters</strong><br>
  Convert PCGEx cluster topology into ZoneGraph lanes and zones.
</p>

<p align="center">
  <a href="https://pcgex.gitbook.io/pcgex">Documentation</a> •
  <a href="https://discord.gg/mde2vC5gbE">Discord</a> •
  <a href="https://www.fab.com/listings/e9d0c0a1-5bae-4dc8-8d17-3f1a1877bf90">FAB</a>
</p>

---

## What is PCGEx + ZoneGraph?

This is a **companion plugin for [PCGEx](https://github.com/Nebukam/PCGExtendedToolkit)** that bridges PCGEx cluster data with Epic's [ZoneGraph plugin](https://dev.epicgames.com/community/learning/tutorials/qz6r/unreal-engine-zonegraph-quick-start-guide), converting cluster topology into ZoneGraph data for AI navigation.

### Experimental Status

Epic's ZoneGraph plugin is **experimental**. Epic warns that "ZoneGraph will have API breaking changes as its development progresses." If something breaks, [open an issue](https://github.com/Nebukam/PCGExElementsZoneGraph/issues) and I'll look into it.

---

## Requirements

- **Unreal Engine 5.8**
- **[PCGExtendedToolkit](https://github.com/Nebukam/PCGExtendedToolkit)** — Core PCGEx plugin (free, MIT licensed); this port targets [commit `866c7c16`](https://github.com/evanSe/PCGExtendedToolkit/commit/866c7c16fa61235f85bca6324fafb2aac9b0c1a8)
- **ZoneGraph** — Epic's experimental ZoneGraph plugin (included with the engine)

### UE 5.8 port provenance

This UE 5.8 port starts from [Evan Seaward's pinned fork commit `a5e7fc89`](https://github.com/evanSe/PCGExtendedToolkitZoneGraph/commit/a5e7fc89bc77ce24f41e8d81ef68fe0c52c7cc52) of [Timothé Lapetite's original PCGEx ZoneGraph plugin](https://github.com/Nebukam/PCGExElementsZoneGraph). The original project metadata, authorship, links, and MIT license are preserved; the port only updates engine and PCGEx compatibility.

---

## Installation

### From FAB
Get the latest release from the **[FAB Marketplace](https://www.fab.com/listings/e9d0c0a1-5bae-4dc8-8d17-3f1a1877bf90)**.

### From Source
1. Clone this repository into your project's `Plugins/` folder
2. Ensure **PCGExtendedToolkit** and **ZoneGraph** are both enabled
3. Regenerate project files and build

---

## License

**MIT License** — Free for personal and commercial use. See [LICENSE](LICENSE) for full terms.

---

## Support

- **[Discord](https://discord.gg/mde2vC5gbE)** — Community support and discussion
- **[Documentation](https://pcgex.gitbook.io/pcgex)** — Guides and tutorials
- **[Patreon](https://www.patreon.com/c/pcgex)** — Support PCGEx development
