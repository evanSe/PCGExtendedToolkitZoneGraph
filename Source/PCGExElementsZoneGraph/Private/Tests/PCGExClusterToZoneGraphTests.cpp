// Copyright 2026 Timothée Lapetite and contributors
// Released under the MIT license https://opensource.org/license/MIT/

#include "Graph/PCGExClusterToZoneGraph.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FPCGExClusterToZoneGraphReversedRoadRadiusAssignmentTest,
	"PCGEx.ZoneGraph.ClusterToZoneGraph.ReversedRoadRadiusAssignment",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPCGExClusterToZoneGraphReversedRoadRadiusAssignmentTest::RunTest(const FString& Parameters)
{
	using namespace PCGExClusterToZoneGraph;

	TestTrue(TEXT("Matching node identity maps to the materialized road start"), IsPrecomputedRoadStart(10, 10));
	TestFalse(TEXT("Opposite single-edge storage direction maps the seed junction to the road end"), IsPrecomputedRoadStart(10, 20));
	TestTrue(TEXT("Reversed materialization maps the other junction to the road start"), IsPrecomputedRoadStart(20, 20));
	TestFalse(TEXT("The other junction never claims the materialized start"), IsPrecomputedRoadStart(20, 10));

	return true;
}

#endif
